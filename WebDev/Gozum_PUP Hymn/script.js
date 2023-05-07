const lyricsContainer = document.querySelector(".lyrics-container");
const lyrics = document.querySelectorAll(".lyric");
const audioPlayer = document.querySelector(".audio-player");

audioPlayer.addEventListener("timeupdate", () => {
  const currentTimestamp = formatTime(audioPlayer.currentTime);
  const currentLyric = document.querySelector(`[data-timestamp = "${currentTimestamp}"]`);

  if (currentLyric) {
    removeHighlight();
    currentLyric.classList.add("highlight");

    // Add past-highlight class to all the lyrics before the current one
    const currentLyricIndex = Array.from(lyrics).indexOf(currentLyric);
    for (let i = 0; i < currentLyricIndex; i++) {
      lyrics[i].classList.add("past-highlight");
    }

    // Scroll to current lyric
    const containerHeight = lyricsContainer.clientHeight;
    const currentLyricTop = currentLyric.offsetTop;
    const currentLyricHeight = currentLyric.clientHeight;
    const containerMiddle = containerHeight / 2;
    const scroll = currentLyricTop - containerMiddle + currentLyricHeight / 2;
    lyricsContainer.scrollTo({ top: scroll, behavior: "smooth" });
  }
});

function removeHighlight() {
  lyrics.forEach((lyric) => {
    lyric.classList.remove("highlight");
    lyric.classList.remove("past-highlight"); // Remove past-highlight class from all lyrics
  });
}

function formatTime(time) {
  const minutes = Math.floor(time / 60);
  const seconds = Math.floor(time % 60);
  return `${minutes}:${seconds < 10 ? "0" + seconds : seconds}`;
}

// Add event listeners to each lyric
lyrics.forEach((lyric) => {
  lyric.addEventListener("click", () => {
    const timestamp = lyric.getAttribute("data-timestamp");
    const [minutes, seconds] = timestamp.split(":");
    const timeInSeconds = parseInt(minutes) * 60 + parseInt(seconds);
    audioPlayer.currentTime = timeInSeconds;
    audioPlayer.play();
  });
});