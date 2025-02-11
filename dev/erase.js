// cursor101 - Glowing Cursor Effect
const cursor101 = document.getElementById('cursor101');

// Function to move the custom cursor
const moveCursor = (e) => {
    cursor101.style.left = `${e.pageX}px`;
    cursor101.style.top = `${e.pageY}px`;
};

// Function to hide the custom cursor
const hideCursor = () => {
    cursor101.style.opacity = '0';
};

// Function to show the custom cursor
const showCursor = () => {
    cursor101.style.opacity = '1';
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
document.addEventListener('mouseleave', hideCursor);

// Show cursor when it enters the window
document.addEventListener('mouseenter', showCursor);