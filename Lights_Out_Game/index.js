

function toggleCross(num) {
	// Initialize Variables
	var count = 0;

	// Toggle the Clicked Cell
	var cell = num.toString();
	cell = 'box' + cell;
	colorChange(cell);

	// If Top Block is in Range
	if ((num - 5) >= 1) {
		var top = num - 5;
		top = top.toString();
		top = 'box' + top;
		colorChange(top);
	}

	// If Bottom Block is in Range
	if ((num + 5) <= 25) {
		var bottom = num + 5;
		bottom = bottom.toString();
		bottom = 'box' + bottom;
		colorChange(bottom);
	}

	// If Right Block is not in Range
	if (((num - 1) % 5) == 0) {
		var right = num + 1;
		right = right.toString();
		right = 'box' + right;
		colorChange(right);
	}

	// If Left Block is not in Range
	else if ((num % 5) == 0) {
		var left = num - 1;
		left = left.toString();
		left = 'box' + left;
		colorChange(left);
	}
	// When it is in Range
	else {
		var right = num + 1;
		right = right.toString();
		right = 'box' + right;
		colorChange(right);

		var left = num - 1;
		left = left.toString();
		left = 'box' + left;
		colorChange(left);
	}

	// Checking if User has Won Yet
	// Iterate through the Cells
	for (var current = 1; current < 26; current++) {
		// Turning the Current Cell Number into String
		current = current.toString();

		// Concatenate to get ID
		var currentID = 'box' + current;

		// Getting the Current Element using ID
		var element = document.getElementById(currentID);

		// Getting the Background Color
		var bgColor = element.style.backgroundColor;

		// Checking if Background color is Green
		if (bgColor == 'green') {
			// increment counter
			count += 1;
		}
	}

	// If None of the Cells are Green
	if (count == 25) {
		// Player Wins -- Display the Popup Message
		alert("You win! YAY!");
	}
}
function    colorChange(ID) {
var button = document.getElementById(ID).style.backgroundColor;
var color = '';
// Making Sure When you Click to get the Opposite 
if (button !== 'green') {
    color = 'green';
    document.getElementById(ID).style.backgroundColor = color;

    }
else if (button === 'green') {
    color = 'red';
    document.getElementById(ID).style.backgroundColor = color;

    }
}

function	randomTable() {
	for (var current = 1; current < 26; current++) {
		// Turning the Current Cell Number into String
		current = current.toString();

		// Concatenate to get ID
		var currentID = 'box' + current;

		// Getting the Current Element using ID
		var element = document.getElementById(currentID);

		// Generating a 0 or 1 at random
		var random = Math.round(Math.random() % 2);

		// Making the Current Cell Red or Green
		if (random == 1) {
			element.style.backgroundColor = 'red';
		} else {
			element.style.backgroundColor = 'green';
		}

	}
}
