const cursor101 = document.getElementById('cursor101');
const fireTrailContainer = document.getElementById('fire-trail');

// Function to create a fire trail element
function createFireTrail(x, y) {
  const fireElement = document.createElement('div');
  fireElement.classList.add('fire-trail-element');
  fireElement.style.left = `${x}px`;
  fireElement.style.top = `${y}px`;
  fireTrailContainer.appendChild(fireElement);

  // Remove the fire element after the animation ends
  fireElement.addEventListener('animationend', () => {
    fireElement.remove();
  });
}
// Function to check if the cursor is inside the viewport
function checkCursorPresence() {
  let cursorInside = false;

  // Detect mouse movement to confirm cursor presence
  document.addEventListener("mousemove", (e) => {
    cursorInside = true;
    cursor101.style.left = `${e.clientX}px`;
    cursor101.style.top = `${e.clientY}px`;
    cursor101.style.opacity = "1";  // Show cursor
  });

  // Detect when the cursor leaves the window
  document.addEventListener("mouseleave", () => {
    cursorInside = false;
  });

  // Run an interval to check if the cursor is missing
  setInterval(() => {
    if (!cursorInside) {
      cursor101.style.opacity = "0";  // Hide cursor
    }
  }, 100); // Check every 100ms
}

// Start monitoring cursor presence
checkCursorPresence();

// Function to move the custom cursor and create fire trail
const moveCursor = (e) => {
  const x = e.clientX;
  const y = e.clientY;

  // Update cursor position
  cursor101.style.left = `${x}px`;
  cursor101.style.top = `${y}px`;

  // Create a fire trail element at the cursor's position
  createFireTrail(x, y);
};

// Event listeners
document.addEventListener('mousemove', moveCursor);
document.addEventListener('mousedown', () => {
  cursor101.classList.add('active');
});
document.addEventListener('mouseup', () => {
  cursor101.classList.remove('active');
});

// Hide cursor when it leaves the window
document.addEventListener('mouseleave', () => {
  cursor101.style.opacity = '0';
});

// Show cursor when it enters the window
document.addEventListener('mouseenter', () => {
  cursor101.style.opacity = '1';
});

const images = [
  "https://i.ibb.co/SDHr8Wzy/Screenshot-2025-02-24-at-11-37-37-bhagvat-geeta-jpg-JPEG-Image-1024-768-pixels.png",
  "https://i.ibb.co/tw3LB0mH/3420085.jpg",
  "https://i.ibb.co/RGH17vhT/Screenshot-2025-02-24-at-11-23-50-english-gita-jpg-JPEG-Image-1600-768-pixels.png",
  "https://i.ibb.co/zLT5zFM/one-person-standing-determined-extreme-adventure-generated-by-ai.jpg",
  "https://i.ibb.co/20dBrR3Z/nasa-Yj1-M5ri-CKk4-unsplash.jpg",
  "https://i.ibb.co/LXKHBgdZ/the-creation-of-adam-4889767-1920.jpg",
  "https://i.ibb.co/cXJj70TD/krishna-arjun-four-vedas-of-krishna-0fo6qeopo0oykh4n.webp"
];

let index = 0;
const environment = document.querySelector(".environment");

// Create an overlay inside .environment to handle the fade effect
const overlay = document.createElement("div");
overlay.style.position = "absolute";
overlay.style.top = "0";
overlay.style.left = "0";
overlay.style.width = "100%";
overlay.style.height = "100%";
overlay.style.background = "black";
overlay.style.opacity = "0";
overlay.style.transition = "opacity 1s ease-in-out";
overlay.style.pointerEvents = "none";
environment.appendChild(overlay);

function changeBackground() {
  overlay.style.opacity = "1"; // Fade to black

  setTimeout(() => {
    index = (index + 1) % images.length;
    environment.style.backgroundImage = `url(${images[index]})`;
    overlay.style.opacity = "0"; // Fade back to normal
  }, 1000); // Wait for fade-out before changing the image
}

setInterval(changeBackground, 5000);

window.addEventListener("resize", () => {
  environment.style.backgroundSize = "cover";
});
/** loading animation--------------------------------------------- */
document.addEventListener("DOMContentLoaded", function () {
  const loadingScreen = document.getElementById("loading-screen");
  const cloudsLeft = document.querySelector(".cloud-left");
  const cloudsRight = document.querySelector(".cloud-right");

  // Wait until page is fully loaded
  window.onload = function () {
    setTimeout(() => {
      // Move clouds away (CoC-style)
      cloudsLeft.classList.add("move");
      cloudsRight.classList.add("move");

      // Hide loading screen after animation
      setTimeout(() => {
        loadingScreen.classList.add("hidden");
      }, 1000);
    }, 5000);
  };
});

