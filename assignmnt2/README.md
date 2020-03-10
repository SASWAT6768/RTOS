server_voip.c:
gcc server_voip.c -lpthread -lpulse-simple -lpulse
./a.out 127.0.0.1 8888


client_voip.c
gcc client_voip.c -lpthread -lpulse-simple -lpulse
./a.out 127.0.0.1 8888
