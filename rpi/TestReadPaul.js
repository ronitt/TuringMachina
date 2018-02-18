//test code for serial input 

var SerialPort = require('serialport');
var port = new SerialPort('/dev/ttyACM1',{ baudRate: 9600});

port.write('main screen turn on', function(err) {
	if (err) {
		return console.log('Error on write: ', err.message);
		
	}
	console.log('message written');
}
);

//open errors will be emitted as an error event
port.on('error', function(err) {
	console.log('Error: ', err.message);
}
);

// Switches the port into "flowing mode"
port.on('data', function (data) {
  console.log('Data:', data);
});

// Read data that is available but keep the stream from entering "flowing mode"
port.on('readable', function () {
  console.log('Data:', port.read());
});
