var http = require('http').createServer(handler), 
    io = require('socket.io').listen(http), 
    fs = require('fs'),
    os = require('os'),
    sp = require("serialport"),
    url = require('url');


const Readline = require('@serialport/parser-readline');


// Connection SerialPort <-> Arduino

var serialPort = new sp('/dev/ttyACM0', 
    {   baudRate: 9600,
        dataBits: 8,
        parity: 'none',
        stopBits: 1,
        flowControl: false
    });
    
const parser = serialPort.pipe(new Readline({ delimiter: '\n' }));
    
serialPort.on("open", function () {
    console.log('serialPort open');
  
});

// Read data from port
parser.on('data', data =>{
  console.log('got word from arduino:', data);
});
    
http.listen(8000);

function handler (req, res) {
  var q = url.parse(req.url, true);
  if(q.query.code == '1234'){
      fs.readFile(__dirname +'/GUI.html',
      function (err, data) {
        if (err) {
          res.writeHead(500);
          return res.end('Error loading GUI.html');
        }

        res.writeHead(200);
        res.end(data);
      });
  } else {
    res.writeHead(301,
            {"Location": "http://192.168.1.21"  + ":"+'8080'});
    res.end();
  }
}

io.sockets.on('connection', function (socket) {
    
    
     socket.on('button update event', function (data) {
        console.log(data.status);
        
        //to toggle button text in client THEN write to serialport

        if(data.status == 'UP'){
            serialPort.write("UP\n");
        }
        if(data.status == 'DOWN'){
            serialPort.write("DOWN\n");
        }
        if(data.status == 'LEFT'){
            serialPort.write("LEFT\n");
        }
        if(data.status == 'RIGHT'){
            serialPort.write("RIGHT\n");
        }
        if(data.status == 'UPRIGHT'){
            serialPort.write("UPRIGHT\n");
        }
        if(data.status == 'UPLEFT'){
            serialPort.write("UPLEFT\n");
        }
        if(data.status == 'DOWNLEFT'){
            serialPort.write("DOWNLEFT\n");
        }
        if(data.status == 'DOWNRIGHT'){
            serialPort.write("DOWNRIGHT\n");
        }
        if(data.status == 'RLEFT'){
            serialPort.write("RLEFT\n");
        }
        if(data.status == 'RRIGHT'){
            serialPort.write("RRIGHT\n");
        }
        
        if(data.status == 'STOP'){
            serialPort.write("STOP\n");
        }
      
    });
});
