#include <iostream>
#include <string>
#include <vector>
#include <openssl/evp.h> 
#include <openssl/aes.h>
#include <openssl/des.h>
#include <openssl/rand.h>

// Helper function to print hex data
void print_hex(const std::string& label, const std::vector<unsigned char>& data) {
    std::cout << label;
    for (unsigned char c : data) {
        std::cout << std::hex << (int)c;
    }
    std::cout << std::dec << std::endl;
}

// Generic encryption function
// WARNING: Do not use EVP_des_ede3_cbc() for new applications. It is insecure.
// Use EVP_aes_256_cbc() instead.
bool encrypt(const std::vector<unsigned char>& plaintext, 
             const std::vector<unsigned char>& key,
             const std::vector<unsigned char>& iv,
             std::vector<unsigned char>& ciphertext,
             const EVP_CIPHER* cipher_type) {

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) return false;

    // Initialize encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, cipher_type, NULL, key.data(), iv.data())) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    int len;
    ciphertext.resize(plaintext.size() + EVP_MAX_BLOCK_LENGTH);

    // Provide the message to be encrypted, and obtain the encrypted output.
    if (1 != EVP_EncryptUpdate(ctx, ciphertext.data(), &len, plaintext.data(), plaintext.size())) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    int ciphertext_len = len;

    // Finalise the encryption.
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext.data() + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    ciphertext_len += len;
    ciphertext.resize(ciphertext_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return true;
}


int main() {
    std::cout << "--- OpenSSL Cryptography Demo ---" << std::endl;

    // --- Secure AES Example ---
    std::cout << "\n## AES-256 (SECURE STANDARD) ##" << std::endl;
    std::vector<unsigned char> aes_key(32); // 256 bits
    std::vector<unsigned char> aes_iv(16); // 128 bits for AES
    RAND_bytes(aes_key.data(), aes_key.size());
    RAND_bytes(aes_iv.data(), aes_iv.size());

    std::string plaintext_str = "A secure message using AES.";
    std::vector<unsigned char> plaintext(plaintext_str.begin(), plaintext_str.end());
    std::vector<unsigned char> aes_ciphertext;

    if (encrypt(plaintext, aes_key, aes_iv, aes_ciphertext, EVP_aes_256_cbc())) {
        print_hex("AES Ciphertext: ", aes_ciphertext);
    } else {
        std::cerr << "AES encryption failed." << std::endl;
    }

    // --- Insecure 3DES Example ---
    std::cout << "\n## 3DES (INSECURE - DEMO ONLY) ##" << std::endl;
    std::vector<unsigned char> des3_key(24); // 192 bits for 3DES
    std::vector<unsigned char> des3_iv(8); // 64 bits for 3DES
    RAND_bytes(des3_key.data(), des3_key.size());
    RAND_bytes(des3_iv.data(), des3_iv.size());
    
    std::vector<unsigned char> des_ciphertext;

    if (encrypt(plaintext, des3_key, des3_iv, des_ciphertext, EVP_des_ede3_cbc())) {
         print_hex("3DES Ciphertext: ", des_ciphertext);
    } else {
        std::cerr << "3DES encryption failed." << std::endl;
    }

    return 0;
}