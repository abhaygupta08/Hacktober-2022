# Python3 program to find modular
# inverse of A under modulo M

# A naive method to find modulor
# multiplicative inverse of A
# under modulo M


def modInverse(A, M):

	for X in range(1, M):
		if (((A % M) * (X % M)) % M == 1):
			return X
	return -1


# Driver Code
if __name__ == "__main__":
	A = 5
	M = 11

	# Function call
	print(modInverse(A, M))

# This code is contributed by Nikita Tiwari.
