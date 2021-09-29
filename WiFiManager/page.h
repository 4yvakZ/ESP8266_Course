const char index_html[] PROGMEM = R"rawliteral(
  <!DOCTYPE html>
<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1" charset="UTF-8">
	<style>
		html {
		 font-family: Arial;
		 display: inline-block;
		 margin: 0px auto;
		 text-align: center;
		}
		h2 { font-size: 3.0rem; }
		p { font-size: 2.0rem; }
		.value {
			width: 50px;
			display: inline-block;
		}
	</style>
</head>
<body>
	<h2>ESP8266 Example</h2>
	<p>
		<span>Hello World</span>
	</p>
</body>
</html>
)rawliteral";
