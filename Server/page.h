const char index_html[] PROGMEM = R"rawliteral(
  <!DOCTYPE html>
<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1" charset="UTF-8">
	<link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
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
		.slider {
			-webkit-appearance: none;
			width: 50%;
			height: 15px;
			border-radius: 5px;
			background: #d3d3d3;
			outline: none;
			opacity: 0.7;
			-webkit-transition: .2s;
			transition: opacity .2s;
		}

		.slider::-webkit-slider-thumb {
			-webkit-appearance: none;
			appearance: none;
			width: 25px;
			height: 25px;
			border-radius: 50%;
			background: #000000;
			cursor: pointer;

		}

		.slider::-moz-range-thumb {
			width: 25px;
			height: 25px;
			border-radius: 50%;
			background: #000000;
			cursor: pointer;
		}

		.red-thumb::-webkit-slider-thumb{
			background: #ff0000;
		}
		.red-thumb::-moz-range-thumb{
			background: #ff0000;
		}

		.green-thumb::-webkit-slider-thumb{
			background: #00ff00;
		}
		.green-thumb::-moz-range-thumb{
			background: #00ff00;
		}

		.blue-thumb::-webkit-slider-thumb{
			background: #0000ff;
		}
		.blue-thumb::-moz-range-thumb{
			background: #0000ff;
		}

		.switch {
		  position: relative;
		  display: inline-block;
		  width: 60px;
		  height: 34px;
		}

		.switch input {
		  opacity: 0;
		  width: 0;
		  height: 0;
		}

		.slider.switch {
		  position: absolute;
		  cursor: pointer;
		  top: 0;
		  left: 0;
		  right: 0;
		  bottom: 0;
		  background-color: #ccc;
		  -webkit-transition: .4s;
		  transition: .4s;
		  border-radius: 34px;
		}

		.slider.switch:before {
		  position: absolute;
		  content: "";
		  height: 26px;
		  width: 26px;
		  left: 4px;
		  bottom: 4px;
		  background-color: white;
		  -webkit-transition: .4s;
		  transition: .4s;
		  border-radius: 50%;
		}

		input:checked + .slider {
		  background-color: #2196F3;
		}

		input:focus + .slider {
		  box-shadow: 0 0 1px #2196F3;
		}

		input:checked + .slider:before {
		  -webkit-transform: translateX(26px);
		  -ms-transform: translateX(26px);
		  transform: translateX(26px);
		}
	</style>
</head>
<body>
	<h2>ESP8266 IoT Lamp</h2>
	<p>
		<i class="fas fa-temperature-high" style="color:#03d1ff;"></i>
		<span class="dht-labels">??????????????????????</span>
		<span id="temperature">%TEMPERATURE%</span>
		<span>&deg;C</span>
	</p>

	<p>
		<i class="fas fa-sun" style="color:#ff9100;"></i>
		<span >????????????????????????</span>
		<span id="brightness">%BRIGHTNESS%</span>
		<span>%</span>
	</p>

	<p>
	<span>R:</span>
	<input type="range" min="0" max="255" value="0" class="red-thumb slider" id="RangeR">
	<span class="value" id="ValueR"></span>
	</p>

	<p>
	<span>G:</span>
	<input type="range" min="0" max="255" value="0" class="green-thumb slider" id="RangeG">
	<span class="value" id="ValueG">	</span>

	</p>

	<p>
	<span>B:</span>
	<input type="range" min="0" max="255" value="0" class="blue-thumb slider" id="RangeB">
	<span class="value" id="ValueB"></span>
	</p>

<p>
<span>????????????</span>
<label class="switch">
  <input type="checkbox" id="Rainbow">
  <span class="slider switch"></span>
</label>
</p>
<p>
<span>??????????????????????</span>
<label class="switch">
  <input type="checkbox" id="Autobrightness">
  <span class="slider switch"></span>
</label>
</p>
</body>
<script>
	var sliders = new Array(document.getElementById("RangeR"),document.getElementById("RangeG"),
		document.getElementById("RangeB"));
	var outputs = new Array(document.getElementById("ValueR"),document.getElementById("ValueG"),
	document.getElementById("ValueB"));

	outputs[0].innerHTML = sliders[0].value;
	sliders[0].oninput = function() {
		outputs[0].innerHTML = this.value;
	}
	outputs[1].innerHTML = sliders[1].value;
	sliders[1].oninput = function() {
		outputs[1].innerHTML = this.value;
	}

	outputs[2].innerHTML = sliders[2].value;
	sliders[2].oninput = function() {
		outputs[2].innerHTML = this.value;
	}

	function sendSlider(element){
		var sliderValue = element.value;
		console.log(sliderValue);
		var xhr = new XMLHttpRequest();
		xhr.open("GET", "/update?slider="+element.id+"&value="+sliderValue, true);
		xhr.send();
	}

	function sendToggle(element){
		var xhr = new XMLHttpRequest();
		if(element.checked){
			xhr.open("GET", "/update?toggle="+element.id+"&state=1", true);
		} else {
			xhr.open("GET", "/update?toggle="+element.id+"&state=0", true);
		}
		xhr.send();
	}

	setInterval(function ( ) {
		var xhttp = new XMLHttpRequest();
		xhttp.onreadystatechange = function() {
				if (this.readyState == 4 && this.status == 200) {
					document.getElementById("temperature").innerHTML = this.responseText;
				}
			};
			xhttp.open("GET", "/temperature", true);
			xhttp.send();
		}, 1000 ) ;

	setInterval(function ( ) {
			var xhttp = new XMLHttpRequest();
			xhttp.onreadystatechange = function() {
				if (this.readyState == 4 && this.status == 200) {
					document.getElementById("brightness").innerHTML = this.responseText;
				}
			};
			xhttp.open("GET", "/brightness", true);
			xhttp.send();
		}, 1000 ) ;
</script>
</html>
)rawliteral";
