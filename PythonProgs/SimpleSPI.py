import spidev
import time
import os
import logging
import datetime
import struct

logging.basicConfig(filename='SpeedTest_IdentifierFirst_Fivebytes_250000Hz.log',level=logging.DEBUG)
logging.info(str(datetime.datetime.now()) + ': Starting Speed Datalog.')

spi = spidev.SpiDev()
spi.open(0,0)

spi.max_speed_hz = 250000
spi.mode = 0b00

DataByte = [0,0,0,0,0]

while True:
    while True:

#   resp = spi.readbytes(2)
#   print resp
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 Array =%s.' %resp)

#   hi = resp[0]
#   print hi
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 High =%s.' %resp[0])
#   lo = resp[1]
#   print lo
#   logging.info(str(datetime.datetime.now()) + ': SPI 16 Low =%s.' %resp[1])

#   actual = 256*hi + lo
#   print actual
#   logging.info(str(datetime.datetime.now()) + ': SPI Actual Value =%s.' %actual)

#   time.sleep(0.1)

##################################################################################
#
#
#
##################################################################################

        identifier = spi.readbytes(1)
        #print identifier

        if identifier[0] == 0xEE:

            print 'Recieved identifier: %s' %identifier
            logging.info(str(datetime.datetime.now()) + ': Recieved identifier =%s.' %identifier)

            Temp = spi.readbytes(1)
            DataByte[0] = Temp[0]
            if DataByte[0] == 0xEE:
                break
            Temp = spi.readbytes(1)
            DataByte[1] = Temp[0]
            if DataByte[1] == 0xEE:
                break
            Temp = spi.readbytes(1)
            DataByte[2] = Temp[0]
            if DataByte[2] == 0xEE:
                break
            Temp = spi.readbytes(1)
            DataByte[3] = Temp[0]
            if DataByte[3] == 0xEE:
                break
            Temp = spi.readbytes(1)
            DataByte[4] = Temp[0]
            if DataByte[4] == 0xEE:
                break

            print 'Recieved Data: %s' %DataByte
            logging.info(str(datetime.datetime.now()) + ': Recieved Data =%s.' %DataByte)

            DropCnt = DataByte[4]

            Int_hi = DataByte[0]
            Int_lo = DataByte[1]
            Int_full = 256*Int_hi + Int_lo
            #print Int_full

            Dec_hi = DataByte[2]
            Dec_lo = DataByte[3]
            Dec_full = 256*Dec_hi + Dec_lo
            #print Dec_full

#        logging.info(str(datetime.datetime.now()) + ': Integer Speed =%s.' %Int_full)
#        logging.info(str(datetime.datetime.now()) + ': Decimal Speed =%s.' %Dec_full)
        #time.sleep(0.1)

            Int_full = float(Int_full)
            Dec_full = float(Dec_full)
            Dec_full = Dec_full / 1000
            ActualSpd = float(Dec_full + Int_full)

            print 'Actual Speed: %s mph' %ActualSpd
            print 'Dropped Messages: %s' %DropCnt

        logging.info(str(datetime.datetime.now()) + ': Actual Speed =%f.' %ActualSpd)
        logging.info(str(datetime.datetime.now()) + ': Dropped Packages =%s.' %DropCnt)

        DataByte = [0,0,0,0,0]
        identifier[0] = 0

####################################################################################
#
#
#
####################################################################################

    #identifier = spi.readbytes(1)
    #print identifier

    #if identifier[0] == 0xEE:

    #    other = spi.readbytes(4)
    #    print other

    #    Int_hi = other[0]
    #    Int_lo = other[1]
    #    Int_full = 256*Int_hi + Int_lo
    #    #print Int_full

    #    Dec_hi = other[2]
    #    Dec_lo = other[3]
    #    Dec_full = 256*Dec_hi + Dec_lo
    #    #print Dec_full

    #    logging.info(str(datetime.datetime.now()) + ': Integer Other =%s.' %Int_full)
    #    logging.info(str(datetime.datetime.now()) + ': Decimal Other =%s.' %Dec_full)
    #    #time.sleep(0.1)

    #    Int_full = float(Int_full)
    #    Dec_full = float(Dec_full)
    #    Dec_full = Dec_full / 1000
    #    Actualother = float(Dec_full + Int_full)

    #    print Actualother
    #    logging.info(str(datetime.datetime.now()) + ': Actual Other =%s.' %Actualother)


###################################################################################
#
#
#
###################################################################################

    #resp = spi.readbytes(4)
    #print resp
    #logging.info(str(datetime.datetime.now()) + ': SPI Float 32 Array =%s.' %resp)

    #for i in range(len(resp)):
       # print resp[i]
       # resp[i] = resp[i]-128
       # print "New adjusted value :%s." %resp[i]

    #value = struct.unpack('<f', struct.pack('4b', *resp))[0]
    #print value

    #value = struct.unpack('<f', resp)
    #print value

##################################################################################

   # time.sleep(0.1)
