const circle = document.getElementById('ball');

const onMouseMove = (e) => {
  circle.style.left = e.pageX - 25 + 'px';
  circle.style.top = e.pageY - 25 + 'px';
};

document.addEventListener('mousemove', onMouseMove);
