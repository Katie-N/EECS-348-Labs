// Get the div containing the paragraph we are styling
paragraphDiv = document.getElementById("paragraphDiv");

// Initialize default values for the paragraph and border colors
// Note that rgb(255,255,255) is white and rgb(0,0,0) is black
pr = 0
pg = 0
pb = 0
br = 0
bg = 0
bb = 0
rgbP = ""
rgbB = ""

// Monitor events on the border width input
widthControl = document.getElementById("width");
widthControl.addEventListener("change", (e) => {
  console.log("New Width is: " + e.target.value);
  paragraphDiv.style.borderWidth = e.target.value + "px";
});

// Monitor events on the R value of the Paragraph input
prControl = document.getElementById("pcolorr");
prControl.addEventListener("change", (e) => {
  console.log("New paragraph R is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    pr = e.target.value;
    updatePColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});
// Monitor events on the G value of the Paragraph input
pgControl = document.getElementById("pcolorg");
pgControl.addEventListener("change", (e) => {
  console.log("New paragraph G is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    pg = e.target.value;
    updatePColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});
// Monitor events on the B value of the Paragraph input
pbControl = document.getElementById("pcolorb");
pbControl.addEventListener("change", (e) => {
  console.log("New paragraph B is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    pb = e.target.value;
    updatePColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});

// Monitor events on the R value of the Paragraph input
brControl = document.getElementById("bcolorr");
brControl.addEventListener("change", (e) => {
  console.log("New Border R is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    br = e.target.value;
    updateBColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});
// Monitor events on the G value of the Paragraph input
bgControl = document.getElementById("bcolorg");
bgControl.addEventListener("change", (e) => {
  console.log("New Border G is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    bg = e.target.value;
    updateBColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});
// Monitor events on the B value of the Paragraph input
bbControl = document.getElementById("bcolorb");
bbControl.addEventListener("change", (e) => {
  console.log("New Border B is " + e.target.value);
  if(e.target.value >= 0 && e.target.value <= 255) {
    bb = e.target.value;
    updateBColor();
  } else {
    console.log("Enter a value between 0 and 255.")
  }
});


function updatePColor() {
  rgbP = "rgb(" + pr + ", " + pg + ", " + pb + ")";
  paragraphDiv.style.color = rgbP;
}

function updateBColor() {
  rgbB = "rgb(" + br + ", " + bg + ", " + bb + ")";
  paragraphDiv.style.borderColor = rgbB;
}
