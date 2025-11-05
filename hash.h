# ifndef HASH_H
# define HASH_H

#include "bibl.h" 

string hashing(string input){

    int val[64];
    size_t size = input.size();

    // handle empty input deterministically
    if (size == 0) {
        for (int i = 0; i < 64; ++i) val[i] = (i * 7 + 3) % 16;
    } else {
        auto byte = [&](size_t idx)->unsigned int { return static_cast<unsigned char>(input[idx % size]); };

        // stronger seed combining first and last byte and length
        val[0] = static_cast<int>(( (byte(0) * 37u) ^ (byte(size - 1) * 17u) ^ (size * 13u) ) & 0xF);

        // primary fill: keep nibble output but mix more nonlinearly
        for (int i = 1; i < 64; ++i) {
            unsigned int b1 = byte(i);
            unsigned int b2 = byte(i - 1);
            unsigned int prev = static_cast<unsigned int>(val[(i - 1) % 64]);

            unsigned int mixed = (b1 * 37u + prev * 13u + b2 * 7u + ((unsigned int)i * 31u)) & 0xFFu;
            mixed = mixed ^ (mixed >> 4); // combine high/low bits
            val[i % 64] = static_cast<int>(mixed & 0xF);

            if (val[i % 64] == static_cast<int>(prev)) val[i % 64] = (val[i % 64] + 1) % 16;
        }

        // fold any remaining bytes (if input longer than 64) back into the state
        if (size > 64) {
            for (size_t i = 64; i < size; ++i) {
                size_t idx = i % 64;
                unsigned int b = byte(i);
                unsigned int mix = (static_cast<unsigned int>(val[idx]) * 3u + b + static_cast<unsigned int>(val[(idx + 17) % 64]) * 5u) & 0xFFu;
                mix = mix ^ (mix >> 3);
                val[idx] = static_cast<int>(mix & 0xF);
                if (val[idx] == val[(idx + 63) % 64]) val[idx] = (val[idx] + 1) % 16;
            }
        }

        // a few diffusion rounds to spread changes across neighbors
        for (int round = 0; round < 4; ++round) {
            int tmp[64];
            for (int k = 0; k < 64; ++k) {
                int a = val[k];
                int b = val[(k + 7) % 64];
                int c = val[(k + 13) % 64];
                int mixed = ((a * 3) ^ (b + c) ^ ((k * 17) & 0xFF)) & 0xFF;
                tmp[k] = (mixed + ((a << 1) | (c >> 2))) & 0xF;
            }
            for (int k = 0; k < 64; ++k) val[k] = tmp[k];
        }
    }

    // format as 64 hex chars (one nibble each)
    stringstream hashed;
    for (int i = 0; i < 64; i++){
        hashed << hex << (val[i] & 0xF);
    }
    return hashed.str();
}

void salt(string &input){

    const string CHARACTERS = "{|}~`_^]@?>=<;:.-,+*)('&%$#![";

    std::random_device rd;
    std::mt19937 generator(rd());

    std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);
    int amount = distribution(generator);
        for (int i = 0; i < amount; i++) {
            input  += CHARACTERS[distribution(generator)];
        }
}

  # endif