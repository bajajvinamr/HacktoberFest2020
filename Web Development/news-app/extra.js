// api url all
//Indian News only
rnum = Math.floor(Math.random() * 12);
console.log(rnum);
list = [
  "business",
  "sports",
  "world",
  "politics",
  "technology",
  "startup",
  "entertainment",
  "miscellaneous",
  "hatke",
  "science",
  "automobile",
];
console.log(list[rnum]);

const api_url = "https://inshortsapi.vercel.app/news?category=" + list[rnum];

// Defining async function
async function getapi(url, int, int) {
  // Storing response
  const response = await fetch(url).then((d) => d.json());

  // Storing data in form of JSON

  console.log(response);
  console.log(response["data"][0]["title"]);

  for (let i = 0; i < 25; i++) {
    img = document.createElement("img");
    img.id = "img" + i;
    img.className = "img";
    img.innerHTML = "style = height: 50vh; width: 100vw; margin: none;";
    img.src = response["data"][i]["imageUrl"];
    document.body.appendChild(img);

    title = document.createElement("p");
    title.id = "title" + i;
    title.className = "title";
    title.innerHTML = response["data"][i]["title"];
    document.body.appendChild(title);

    content = document.createElement("p");
    content.id = "content" + i;
    content.className = "content";
    content.innerHTML = response["data"][i]["content"];
    document.body.appendChild(content);

    btn = document.createElement("button");
    btn.id = i.toString();
    btn.className = "btn";
    btn.innerHTML = '<i class="fas fa-volume-up"></i>';
    btn.style = "style= font-size: 20px;";
    document.body.appendChild(btn);

    link = document.createElement("a");
    link.innerHTML = '<span class="fas fa-arrow-right"></span>';
    link.className = "next";
    link.href = "#img" + (i + 1);
    document.body.appendChild(link);
  }
  document.querySelectorAll(".btn").forEach((item) => {
    item.addEventListener("click", (e, i) => {
      console.log(e.currentTarget.id);
      let id = parseInt(e.currentTarget.id);
      newstr =
        response["data"][id]["title"] +
        "." +
        "News By" +
        response["data"][id]["author"] +
        "." +
        response["data"][id]["content"] +
        response["data"][id]["date"] +
        response["data"][id]["time"];
      console.log(newstr);
      responsiveVoice.speak("Top news today", "Hindi Female", {
        volume: 1,
        rate: 0.9,
        pitch: 1,
      });
      responsiveVoice.speak(newstr, "Hindi Female", {
        volume: 1,
        rate: 0.9,
        pitch: 1,
      });
    });
  });
}

getapi(api_url, 10, 10);
