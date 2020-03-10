**Challenges Faced and solving approach **
1)Voice not transmitting
*tried to reading into a file and then transmitting from it from the server side but latency was very high.
2)Garbage sound passing
*Instead of running separate threads for receive and send i included them all in a single main function.
still could not figure out what sound was passing

**Challenges unsolved**
1) Voices are being repeated many times
2) Both sender and receiver are being able to listen to the other side as well as its own voice.

* TRied to include 
load-module module-echo-cancel source_name=baresip aec_method=webrtc format=s16le rate=8000 channels=1
set-default-source baresip
set-default-sink 2
in the /etc/pulse/system.pa file at the end .
i did not notice any  significant changes .

3)A shrill voice keeps on rising in the background which forces the user to mute the audio at a point.


**Specification**
* Format = PA_SAMPLE_S16LE
* Rate = 44100
* Channels = 2
