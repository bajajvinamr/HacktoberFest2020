var video = document.getElementById("video");
var j = 0;

function playM3u8(url) {
  if (Hls.isSupported()) {
    video.volume = 0.3;
    var hls = new Hls();
    var m3u8Url = decodeURIComponent(url);
    hls.loadSource(m3u8Url);
    hls.attachMedia(video);
    hls.on(Hls.Events.MANIFEST_PARSED, function () {
      video.play();
    });
    document.title = url;
  } else if (video.canPlayType("application/vnd.apple.mpegurl")) {
    video.src = url;
    video.addEventListener("canplay", function () {
      video.play();
    });
    video.volume = 0.3;
    document.title = url;
  }
}

function playPause() {
  video.paused ? video.play() : video.pause();
}

function volumeUp() {
  if (video.volume <= 0.9) video.volume += 0.1;
}

function volumeDown() {
  if (video.volume >= 0.1) video.volume -= 0.1;
}

function seekRight() {
  video.currentTime += 5;
}

function seekLeft() {
  video.currentTime -= 5;
}

function vidFullscreen() {
  if (video.requestFullscreen) {
    video.requestFullscreen();
  } else if (video.mozRequestFullScreen) {
    video.mozRequestFullScreen();
  } else if (video.webkitRequestFullscreen) {
    video.webkitRequestFullscreen();
  }
}

playM3u8(window.location.href.split("#")[1]);
$(window).on("load", function () {
  $("#video").on("click", function () {
    this.paused ? this.play() : this.pause();
  });
  Mousetrap.bind("space", playPause);
  Mousetrap.bind("up", volumeUp);
  Mousetrap.bind("down", volumeDown);
  Mousetrap.bind("right", seekRight);
  Mousetrap.bind("left", seekLeft);
  Mousetrap.bind("f", vidFullscreen);
});

subreddit = ["IndianDankMemes","BikiniBottomTwitter", "AdviceAnimals", "MemeEconomy",
            "ComedyCemetery", "memes", "PrequelMemes", "PewdiepieSubmissions",
            "terriblefacebookmemes", "funny", "wholesomememes", "raimimemes",
            "historymemes", "okbuddyretard", "im14andthisisdeep", "puns", "nnn",
            "Community", "Puns", "IndianMeyMeys", "IndiaSpeaks", "IndianMemeTemplates", "indiameme", 
            "MemeAlleyway", "MemeChimera", "memeconvention", "india", "funnyindianvideo"
            , "Indiafunny", "meme", "MemePiece", "dankvideos", "PlayItAgainSam"];
var randomInt = Math.floor(Math.random() * 33);
var sectionInt = Math.floor(Math.random() * 5);
sections = ["top", "", "new", "hot", "rising"];
console.log(subreddit[randomInt], sections[sectionInt]);

const api_url = `https://www.reddit.com/r/${subreddit[randomInt]}/${sections[sectionInt]}.json`;

var hls_urls = [];

async function getapi(url, int, int) {
  const response = await fetch(url).then((d) => d.json());
  for (let i = 0; i < response["data"]["children"].length; i++) {
    try {
      console.log(
        response["data"]["children"][i]["data"]["media"]["reddit_video"][
          "hls_url"
        ],
        "hls url"
      );
      hls_urls.push(
        response["data"]["children"][i]["data"]["media"]["reddit_video"][
          "hls_url"
        ]
      );
      console.log(
        response["data"]["children"][i]["data"]["permalink"],
        "permalink"
      );
    } catch (error) {
      const e = new ErrorEvent("error", { message: "my error", error: error });
      window.dispatchEvent(e);
    }
    console.log(i);
  }
}

getapi(api_url, 10, 10);

function nextVideo() {
  $("#source").attr(
    "src",
    "https://v.redd.it/5xnc72zz72a81/HLSPlaylist.m3u8?a=1644069393%2CM2QzZWU0OWZlMDhkNDEzNGQ2OGVlZTZlNmMyYjZmOGU3NDk0MDUwZjdmYTkwNjIxYjk1YjgzZWIyYmZhYjMzYg%3D%3D&amp;v=1&amp;f=sd"
  );
  console.log("found");
}

console.log(hls_urls);

function delay(milisec) {
  return new Promise(async (resolve) => {
    setTimeout(() => {
      resolve("");
    }, milisec);
  });
}

function next() {
  playM3u8("https://yashdkadam.github.io/m3u8-player/player/#"+hls_urls[j]);
  j++;
}

function load() {
  navigator.clipboard.writeText(
    "https://redditsave.com/info?url=" + hls_urls[j - 1]
  );
}
