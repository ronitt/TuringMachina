// paul to pi to arduino 

var SerialPort = require('serialport');
var portRx = new SerialPort('/dev/ttyACM1',{ baudRate: 9600});
var portTx = new SerialPort('/dev/ttyACM0',{ baudRate: 9600});
var message;

//---------------- Receiver code starts-----------------------------------
portRx.write('Reciever port check', function(err) {
	if (err) {
		return console.log('Error on write Rx: ', err.message);
		
	}
	console.log('Rx ON');
}
);

//open errors will be emitted as an error event
portRx.on('error', function(err) {
	console.log('Error: Rx', err.message);
}
);
//---------------------Read------------------------------------------------
// Switches the port into "flowing mode"
portRx.on('data', function (data) {
  console.log('DataRx:', data);
});

// Read data that is available but keep the stream from entering "flowing mode"
portRx.on('readable', function () {
  message = port.read();
  console.log('DataRx:', message);
});

//-------------------Tx Code starts --------------------------------
portTx.write('Transmitter port check', function(err) {
	if (err) {
		return console.log('Error on write TxOpen: ', err.message);
		
	}
	console.log('Tx ON');
}
);

//open errors will be emitted as an error event
portTx.on('error', function(err) {
	console.log('Error: Tx', err.message);
}
);
//---------------------Write--------------------------------------------
portTx.write(message, function(err) {
	if (err) {
		return console.log('Error on write message: ', err.message);
		
	}
	console.log('Message sent');
}
);