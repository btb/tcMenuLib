/*
 * Copyright (c) 2018 https://www.thecoderscorner.com (Nutricherry LTD).
 * This product is licensed under an Apache license, see the LICENSE file in the top-level directory.
 */

/**
 * @file SerialTransport.h
 * 
 * Serial remote capability plugin. This file is a plugin file and should not be directly edited,
 * it will be replaced each time the project is built. If you want to edit this file in place,
 * make sure to rename it first.
 */

#ifndef _TCMENU_SERIALTRANSPORT_H_
#define _TCMENU_SERIALTRANSPORT_H_

#include <Arduino.h>
#include "RemoteConnector.h"

/**
 * Serial transport is an implementation of TagValueTransport that works over a serial port
 */
class SerialTagValueTransport : public TagValueTransport {
private:
	Stream* serialPort;
public:
	SerialTagValueTransport();
	virtual ~SerialTagValueTransport() {}
	void setStream(Stream* stream) {this->serialPort = stream; }

	virtual void flush()                   {serialPort->flush();}
	virtual int writeChar(char data)       { return serialPort->write(data); }
	virtual int writeStr(const char* data) { return serialPort->write(data); }

	virtual uint8_t readByte()   { return serialPort->read(); }
	virtual bool readAvailable() { return serialPort->available(); }
	virtual bool available()     { return serialPort->availableForWrite();}
	virtual bool connected()     { return true;}

	virtual void close();

};

/**
 * SerialTagValServer is the implementation of remote communication that provides
 * remote menu capability for Serial streams.
 */
class SerialTagValServer {
private:
	SerialTagValueTransport serPort;
	TagValueRemoteConnector connector;
public:
	/** Empty constructor - configured in begin */
	SerialTagValServer();
	/**
	 * Begins serial communication on the given port. You must call begin on the stream first.
	 * @param portStream the stream upon which to communicate, it must be already opened.
	 * @param namePgm the local name of the application in PROGMEM
	 */ 
	void begin(Stream* portStream, const char* namePgm);
	/**
	 * Arranged internally don't call yourself.
	 */ 
	void runLoop();

	/** returns the remote connector associated with the connection */
	TagValueRemoteConnector* getRemoteConnector(int /*num*/) {return &connector;}
};

/**
 * the global instance of the SerialTagValServer
 */
extern SerialTagValServer remoteServer;

#endif /* _TCMENU_SERIALTRANSPORT_H_ */
