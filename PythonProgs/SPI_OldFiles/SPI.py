import time
import sys
import spidev

spi = spidev.SpiDev()
spi.open(0,0)

def buildReadCommand(channel):
    startBit = 0x01
    singleEnded = 0x08

    # Return python list of 3 bytes
    #   Build a python list using [1, 2, 3]
    #   First byte is the start bit
    #   Second byte contains single ended along with channel #
    #   3rd byte is 0
    return []

def processAdcValue(result):
    '''Take in result as array of three bytes.
    Return the two lowest bits of the 2nd byte and
    all of the third byte'''
    pass

def readAdc(channel):
    if ((channel > 7) or (channel < 0)):
        return -1
    r = spi.xfer2(buildReadCommand(channel))
    return processAdcValue(r)

if __name__ == '__main__':
    try:
        while True:
            val = readAdc(1)
            print "ADC Result: ", str(val)
            time.sleep(5)

    except KeyboardInterrupt:
        spi.close()
        sys.exit(0)
