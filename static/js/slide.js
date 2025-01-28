let currentSlide = 0;
const slides = document.querySelectorAll('.banner-slide');
const totalSlides = slides.length;

// 초기 설정: 첫 번째 슬라이드 보이기
slides[currentSlide].style.display = 'block';

// 슬라이드 변경 함수
function changeSlide(next = true) {
    slides[currentSlide].style.display = 'none'; // 현재 슬라이드 숨기기
    currentSlide = next
        ? (currentSlide + 1) % totalSlides // 다음 슬라이드
        : (currentSlide - 1 + totalSlides) % totalSlides; // 이전 슬라이드
    slides[currentSlide].style.display = 'block'; // 새로운 슬라이드 보이기
}

// 이전, 다음 버튼 동작
document.querySelector('.prev').addEventListener('click', () => changeSlide(false));
document.querySelector('.next').addEventListener('click', () => changeSlide(true));

// 자동 슬라이드 (3초 간격)
setInterval(() => changeSlide(true), 3000);
