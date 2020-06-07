<link href="style.css" rel="stylesheet"/>

# 1. Omniwheeled Mobile Robot


<div style="text-align: center">
<img src="./images/show.gif" alt="alt text" width="" height="whatever">
</div>


<div justify style="text-align: justify;  max-width: 500px;">

## Introduction to the Mobile Robots


Mobile robots can be divided according to the power transmission system of a robot. The popularization of the automation systems has caused a huge interest in designing and inventing new things by amateur constructors. These kind of robots are not only used in competitions or shows but also in real industry and production process.
One of the most important features of mobile robots is its high manoeuvrability and freedom of movement. An interesting solution is in taking advantage of special omnidirectional wheels also called as rollers. The wheels allow moving in every direction without rotation. It means that it is possible to change the direction of movement (orientation) in place. This solution makes it possible to apply in different technology fields like internal transport, logistics, research, monitoring and among others.
A classification of the robots can be carried out on the construction or type of control. The classification division of robots can be done by its kinematic structure:

<ul>
<li> Stationary robots</li>
<li> Mobile robots</li>
</ul>



### **Division of mobile robots**

Due to various way of movements, mobile robots can group them into categories:

<ul>
<li> Flying</li>
</ul>

<ul>
<li> Circular</li>
</ul>

<ul>
<li> Tracking</li>
</ul>

<ul>
<li> Floating</li>
</ul>

<ul>
<li> Walking</li>
</ul>

<ul>
<li> Crawling</li>
</ul>

<ul>
<li> Hybrid</li>
</ul>



### **Omniwheels kinematics**

An application of the mobile robot with the multidirectional unit allows a holonomic movement on the plane. Robot's movement range is limited to four different directions and rotary motion. The purple arrows indicate the direction of the robot's movement, while the green arrows determine the rotation of each individual DC motor.  


<ul>
<li><b>Main movement</b> - consists of two distinct directions, the robot moves with all four electrical motors running synchronously.
</li>
</ul>
<div style="text-align: center">
<img src="./images/track-1.png" alt="alt text" width="500" height="whatever">
</div>
<ul>
<li>
<b>Auxiliary movement</b> - consists of two successive directions, auxiliary movement is possible thanks to the synchronous operation of only two DC motors.
</li>
</ul>

<div style="text-align: center">
<img src="./images/track-2.png" alt="alt text" width="500" height="whatever">
</div>
<ul>
<li>
<b>Rotational movement</b> - consists of synchronous DC motors work, all of them rotate in the same direction. 
</li>
</ul>

<div style="text-align: center">
<img src="./images/track-3.png" alt="alt text" width="500" height="whatever">
</div>

### **Block diagram concept (1)**

The first idea was to extend the already existing project developed by Mateusz Musiałowski. His thought was to control such a robot via Bluetooth connection. Afterwards, he decided to code an android application to navigate a robot. Therefore this project can be extended and reused once again. In this case, Raspberry Pi will be mounted at the top of the robots cover.       

<div style="text-align: center">
<img src="./images/block.png" alt="alt text" width="500" height="whatever">
</div>


### **Block diagram concept (2)**

In this scenario, there is no need to use Arduino in order to control electrical motors. An external DC motor controller can be used directly on Raspberry Pi. This external hat can be found [here](https://wiki.dfrobot.com/DC_Motor_Driver_HAT_SKU_DFR0592).


### **Custom Arduino PCB shield**


### **Model 3D**


A 3D cover was designed in SolidWorks and later done on a 3D printer. Results are presented below.
<div style="text-align: center">
<img src="./images/model-1.png" alt="alt text" width="500" height="whatever">
</div>

<div style="text-align: center">
<img src="./images/model-2.png" alt="alt text" width="500" height="whatever">
</div>

<div style="text-align: center">
<img src="./images/model-3.png" alt="alt text" width="500" height="whatever">
</div>






# 2. Overview of web technologies

## Introduction

The idea of this project is to control a mobile robot via local wifi using only basic web technologies. Therefore the usage of well-known HTTP protocol is reasonable and will be implemented. The biggest advantage of using web application is the fact that we are not restricted to any operating system. This application will be running in a web browser. Client-Server architecture allows to separate Frontend and Backend code, in this case, the server contains the whole functionality and client renders user interface.

## Web Technologies
<div style="text-align: justify; max-width: 700px;">



HTTP provides stable data transmission with the following principle: 
<ul>
<li>Server - program providing services for a client, it awaits incoming requests from a client.</li>
</ul>

<ul>
<li>Client - requests a server's content or service, does not offer any resource and initiates a communication session.</li>
</ul>

### What is the difference between Web App and Website ?

<b>Web Application</b> is a program based on Client-Server architecture which requires a stable Internet connection in order to communicate with the server. The server is responsible for receiving and processing data then resends answer for request. Currently the standard communication protocol in a global network WWW is HTTP (<em>Hypertext Transfer Protocol</em>) with its encrypting version HTTPS (<em>Hypertext Transfer Protocol Secure</em>). In order to encrypt sending files, there is mainly applied SSL protocol (<em>Secure Socket Layer</em>) together with transport layer TLS (<em>Transport Layer Security</em>) preventing data interception.

<b>Website</b> is a rendered content of HTML file creating primarily in HTML, CSS and JavaScript. There are two distinguished types of websites:
<ul>
<li>
<b>Dynamic</b> - taking advantage of more complex model as CMS (<em>Content Management System</em>), it contains dynamic rendered templates and scripts depending on server requests.
</li>
</ul>
<ul>
<li>
<b>Static</b> - content is rendered while loading a webpage, all files are sent to the user so it doesn't need to send requests to the server. 
</li>
</ul>

 ### What is basically a Web Browser? 

<b> Web Browser</b> is a program that gets connected to the WWW using an unique URL address (<em>Uniform Resource Locator</em>). This program downloads and presents processed data if a form of website or web app available on the web. 


Before getting into the project, let's see which technologies can be used as well on Frontend as Backend.

![Frontend](/images/frontend.png)

![Backend](/images/backend.png)

## Programming languages

1. HTML
2. CSS
3. JavaScript 
   - [Node.js](https://nodejs.org/en/about/)
   - [Express.js](https://expressjs.com/en/4x/api.html#app) </br>
      get - method downloading indicated resources from the server</br>
      post - method sending data from client to the server</br>
      put - method updating sending data from client to the server</br>
      delete - method deleting indicated resources from the server 
   - [Socket.io](https://socket.io/docs/server-api/)
   - [SerialPort](https://serialport.io/docs/guide-about)
   
### **Raspberry Pi**


### **Arduino** 

</div>
