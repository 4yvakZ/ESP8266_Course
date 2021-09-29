const char start[] = R"rawliteral(
	<!DOCTYPE html>
	<html>
	<head>
		<meta name="viewport" content="width=device-width, initial-scale=1" charset="UTF-8">
		<title>ESP8266 TV Holder</title>
		<style>
			html {
			 font-family: Arial;
			 display: inline-block;
			 margin: 0px auto;
			 text-align: center;
			}
			h2 { font-size: 3.0rem; }
			p { font-size: 2.0rem; }
			body {
				max-width: 600px;
				margin:0px auto;
				padding-bottom: 25px;
			}

			.value {
				width: 50px;
				display: inline-block;
			}

			.button{
				font-size: 1.5rem;
			}

	    .slider {
				-webkit-appearance: none;
				margin: 14px;
				width: 360px;
				height: 25px;
				background: #FFD65C;
	      outline: none;
				-webkit-transition: .2s;
				transition: opacity .2s;
			}

	    .slider::-webkit-slider-thumb {
				-webkit-appearance: none;
				appearance: none;
				width: 35px;
				height: 35px;
				background: #003249;
				cursor: pointer;
			}

	    .slider::-moz-range-thumb {
				width: 35px;
				height: 35px;
				background: #003249;
				cursor: pointer;
			}

		</style>
	</head>
	<body>
		<h2>ESP8266 TV Holder</h2>
	  <p>
			<span class="value" id="text0"></span>
			<input type="range" onchange="sendSlider(this)" id="slider0" min="0" max="180" value=")rawliteral";

const char middle[] = R"rawliteral(" step="1" class="slider">
		</p>
		<p>
			<span class="value" id="text1">%SLIDERVALUE1%</span>
			<input type="range" onchange="sendSlider(this)" id="slider1" min="0" max="180" value=")rawliteral";

const char end[] = R"rawliteral(" step="1" class="slider">
		</p>
		<script>
			var sliders = new Array(document.getElementById("slider0"),document.getElementById("slider1"));
			var outputs = new Array(document.getElementById("text0"),document.getElementById("text1"));

			outputs[0].innerHTML = sliders[0].value;
			sliders[0].oninput = function() {
				outputs[0].innerHTML = this.value;
			}
			outputs[1].innerHTML = sliders[1].value;
			sliders[1].oninput = function() {
				outputs[1].innerHTML = this.value;
			}

			function sendSlider(element) {
				var sliderValue = element.value;
				var xhr = new XMLHttpRequest();
				xhr.open("GET", "/update?slider="+element.id+"&value="+sliderValue, true);
				xhr.send();
			}
		</script>
	</body>
	</html>
)rawliteral";
