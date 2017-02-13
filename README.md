# Serial-Over-OOK
Simple code to take 5v RS232 over very cheap radio modules.

I don't intend for this software to ever be used in "production" or in a commercial setting.
It is just an experimental proof of concept and is horrific.

It does "work" however !

Best used with something like ax25 to give you a robust link.
But if youre thinking of linking two systems together with this, there is amost certanly a better way of doing it !!

The methodology was to either collect a full message (90 ish bytes !) and send it or time out (10ms) and send what you've got in the buffer.

This seems to work. It is very slow.

I used the fs1000a and associated reciver (rf-5v?) 
