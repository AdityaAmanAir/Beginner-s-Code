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