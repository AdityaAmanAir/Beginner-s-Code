const fancyHr = document.querySelector('.fancy-hr');

window.addEventListener('mousemove', (event) => {
    const rect = fancyHr.getBoundingClientRect();
    if (event.clientY > rect.bottom) {
        fancyHr.classList.add('glowing');
    } else {
        fancyHr.classList.remove('glowing');
    }
});

window.addEventListener('mouseout', () => {
    fancyHr.classList.remove('glowing');
});
