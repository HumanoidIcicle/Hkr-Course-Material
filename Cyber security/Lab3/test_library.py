from passlib.hash import nthash, sha512_crypt, argon2

def test_algorithm(algo, algo_name):
    print(f"\n==================== Testing {algo_name} ====================")
    
    password1 = "PasswOrd123"
    password2 = "ThisIsAVeryLongerPassw0rd4Security"

    # Hash the shorter password
    once_hashed_password1 = algo.hash(password1)
    print(f"\nOnce Hashed Password1: {once_hashed_password1}")
    twice_hashed_password1 = algo.hash(password1)
    print(f"\nTwice Hashed Password1: {twice_hashed_password1}")

    # Hash a longer password
    once_hashed_password2 = algo.hash(password2)
    print(f"\nOnce Hashed Password2: {once_hashed_password2}")
    twice_hashed_password2 = algo.hash(password2)
    print(f"\nTwice Hashed Password2: {twice_hashed_password2}")

    # Verify the password
    is_correct = algo.verify(password1, once_hashed_password1)
    print(f"\nPassword verification result: {is_correct}")

def main():
    test_algorithm(nthash, "nthash")
    test_algorithm(argon2, "argon2")
    test_algorithm(sha512_crypt, "sha512_crypt")

if __name__ == "__main__":
    main()