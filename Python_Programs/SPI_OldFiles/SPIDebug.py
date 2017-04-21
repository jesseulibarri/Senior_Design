import spidev
from time import sleep

DEBUG = 0

spi = spidev.SpiDev()
spi.open(0,0)

def get_adc(channel):
        if ((channel > 1) or (channel < 0)):
                return -1

        r = spi.xfer2([1,(2+channel)<<6,0])
        ret = ((r[1]&31) << 6) + (r[2] >> 2)
        return ret

A0o = 0
A1o = 0
while True:
        A0 = get_adc(0)
        if A0 != A0o:
                print "A0:", A0
                A0o = A0
        A1 = get_adc(1)
        if A1 != A1o:
                print "A1:", A1
                A1o = A1
        sleep(0.2)
