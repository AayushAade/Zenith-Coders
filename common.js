function playAudio(id, event) {
      const audio = document.getElementById(id);
      const card = event.currentTarget;

      if (audio) {
        audio.currentTime = 0;
        audio.play();
      }

      // Trigger rotation animation
      card.classList.add('clicked');
      setTimeout(() => card.classList.remove('clicked'), 500);
    }

    // Fish follows mouse
    const fish = document.getElementById('fish');
    document.addEventListener('mousemove', (e) => {
      fish.style.transform = `translate(${e.clientX}px, ${e.clientY}px)`;
    });
    function toggleMenu() {
  const navLinks = document.getElementById('navLinks');
  navLinks.classList.toggle('show');
    }
