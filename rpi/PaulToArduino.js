// paul to pi to arduino 

var SerialPort = require('serialport');
var portRx = new SerialPort('/dev/ttyACM1',{ baudRate: 9600});
var portTx = new SerialPort('/dev/ttyACM0',{ baudRate: 9600});
var message = Buffer.alloc(10);

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
  console.log('DataRx:', data.toString('utf-8'));
  //var hold = data.toString('utf-8');
  //data.write(hold.concat('\0'), 'utf-8');
  portTx.write(data, function(err){
	if (err){
		return console.log('Error: ', err.message);
	}
	console.log('sent');
  });
});

// Read data that is available but keep the stream from entering "flowing mode"
/*
portRx.on('readable', function () {
  message = port.read('','',8);
  console.log('loop start');
  console.log('DataRx:', message);
  console.log('loop check');
});
*/

portRx.on('readable',function() {
  port.read(message, 0, 10);
 // console.log('DataRx: ', message);
  portTx.write(message.toString('utf-8'), function(err) {
      if(err){
               return console.log('Error on write message: ', err.message);
      }
      console.log('Message sent');
});
}
);
//-------------------Tx Code starts --------------------------------
/*
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
*/
//---------------------Write--------------------------------------------
/*
portTx.write(message, function(err) {
	if (err) {
		return console.log('Error on write message: ', err.message);
		
	}
	console.log('Message sent');
}
);
*/
