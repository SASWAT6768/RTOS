# Assignment-1
# Multi-Client-Server-Chat
Group chat program where there is a single server and multiple clients. The server simply forwards a client's message to all the other clients

Platform: Linux with GCC compiler

Compiling: gcc filename.c -lpthread

Running the server: ./a.out portnumber I.P addr
Running the clients: ./a.out username portnumber I.P addr

Stopping the chat from client side: CTRL-C will prompt yes or no to quit

Note:The portnumber provided to clients should be same as the one given to server. Username to recognise of source of the message

[I RAN THE PROGRAM WITH PORT -8888 AND IP-127.0.0.1]

##PERFORMANCE REPORT WITH INCREASING NO. OF CLIENTS
I created one executibe (./a.out) with gcc for single client after that for having N client connections I executed ./a.out 
(N-1) times using "parallel -j (N-1)" command . 
I measured all the processing times in nanosecs while sending "hello" from one client .
