from cryptography.hazmat.primitives.asymmetric import rsa
from cryptography.hazmat.primitives import serialization


PRIVATE_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPrivate.pem"
PUBLIC_FILE = "C:\\Users\\JOSS0001\\OneDrive - Högskolan Kristianstad\\Cyberpunk\\Crypto Mines\\Lab2\\myPublic.pem"

def gen_priv_key():
    private_key = rsa.generate_private_key(
    public_exponent=65537, # The public exponent of the new key
    key_size=2048 # Length of the modulus in bits
    ) # Returns an instance of the RSAPrivate key

    return private_key

def main():
    password = input("Enter password: ")

    priv_key = gen_priv_key() # Generate private key
    pub_key = priv_key.public_key() # extract public key

    # Serialize and encrypt the private key
    # Serializing converts RSA object into file saveable format
    # PEM encodes data in b64 and also adds header and footer to the file
    priv_pem = priv_key.private_bytes(
        encoding=serialization.Encoding.PEM, #Encode using pem encoding
        format=serialization.PrivateFormat.TraditionalOpenSSL,
        #Encrypt using the password
        encryption_algorithm=serialization.BestAvailableEncryption(password.encode())
    )

    pub_pem = pub_key.public_bytes(
        encoding=serialization.Encoding.PEM,
        format=serialization.PublicFormat.SubjectPublicKeyInfo
    )
    with open(PRIVATE_FILE, "wb") as file:
            file.write(priv_pem)

    with open(PUBLIC_FILE, "wb") as file:
            file.write(pub_pem)

    print(f"==== Private key saved to {PRIVATE_FILE} ====")
    print(f"==== Public key saved to {PUBLIC_FILE} ====")

if __name__ == "__main__":
    main()
