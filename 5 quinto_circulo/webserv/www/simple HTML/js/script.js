const burger = document.getElementById('burgerMenu');
const sidebar = document.getElementById('sidebar');
const burgerIcon = burger.querySelector('i');

burger.onclick = function() {
    sidebar.classList.toggle('open');
    burger.classList.toggle('open');
    if (sidebar.classList.contains('open')) {
        burgerIcon.classList.remove('fa-burger');
        burgerIcon.classList.add('fa-xmark');
    } else {
        burgerIcon.classList.remove('fa-xmark');
        burgerIcon.classList.add('fa-burger');
    }
};