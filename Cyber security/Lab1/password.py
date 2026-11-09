import os
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC

def gen_key(salt):
    password = input("Enter a password: ")
    password = password.encode() # Password to bytes

    # Derive
    kdf = PBKDF2HMAC(
        algorithm=hashes.SHA256(), # Hashing algorithm to use
        length=32, # Length of the key to be derived
        salt=salt, # 
        iterations=1_600_000, # Number of iteration to perform of the hash, 
    )
    key = kdf.derive(password) # Derive key from password
    temp = [salt, key]

    return tuple(temp)

def main():
    # Salts should be randomly generated
    salt = os.urandom(16) # Salt to ensure same passwords give diff hash output

    print(gen_key(salt))
    print()
    print()

if __name__ == "__main__":
    main()
