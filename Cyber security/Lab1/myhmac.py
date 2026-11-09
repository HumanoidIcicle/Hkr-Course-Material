import os
from cryptography.hazmat.primitives import hashes, hmac

def generate_mac(key, msg):
    h = hmac.HMAC(key, hashes.SHA256()) #Create hashing object
    h.update(msg) #The byte msg to hash and authenticate

    signature = h.finalize() #Finalize generates the hmac
    return key + signature #Return the key and mac value

def verify_mac(key, msg, mac):
    # Rehash the message, same message gets same mac
    h = hmac.HMAC(key, hashes.SHA256())
    h.update(msg)

    got_sign = mac[16:] # Retrieve only the mac value from received authentication message

    try:
        # verify() raises an exception if they are different.
        h.verify(got_sign) # Using inbuilt verify method to check correct mac
        return True # Return true if verify doesnt throw any errors
    except:
        return False

def main():
    key = os.urandom(16)
    msg = input("\nMessage: ").encode()
    msg2 = "Wrong message".encode()

    hashed = generate_mac(key, msg)

    print("\nMAC: ")
    print(hashed)
    print("\nSize: ")
    print(len(hashed[16:]))
    print("\nVerified MAC: ")
    print(verify_mac(key, msg, hashed))


if __name__ == "__main__":
    main()
