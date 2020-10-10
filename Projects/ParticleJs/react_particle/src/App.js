import React from 'react';
import Particles from 'react-particles-js';
import Google from './google.png';
import './App.css';
import Switch from './switch';

function App() {
  const[darkMode,setDarkMode] = React.useState(getInitialMode())

  React.useEffect(() => {
    localStorage.setItem('dark', JSON.stringify(darkMode));
  },[darkMode])

  function getInitialMode(){
    const isReturningUser = "dark" in localStorage;
    const savedMode = JSON.parse(localStorage.getItem('dark'));
    const userPreferDark = getPrefColorScheme();
    // if mode was saved -> dark/light
    if(isReturningUser){
      return savedMode;

    // if preferred color scheme is dark -> dark
    } else if(userPreferDark){
      return true;

       // otherwise -> dark
    } else{
      return false;
    }
  }

  function getPrefColorScheme(){
    if(!window.matchMedia) return;
    return window.matchMedia("(prefers-color-scheme:dark)").matches;
  }

  return (
   
      <div className={darkMode ? "dark-mode" : "light-mode"}>
       
         <div className="app">
         <nav className="toogle-container">
            <span>{darkMode ? "Dark Mode" : "Light Mode"}</span>
            <Switch
              className="switch"
              isOn={darkMode}
              handleToggle={() => setDarkMode(prevMode => !prevMode)}
            />
           </nav>
              <Particles className="particles"
                params={{
                  particles: {
                    number: {
                      value: 100,
                      density: {
                        enable: true,
                        value_area: 800
                      }
                    },
                    color: {
                      value: ["#4285F4", "#EA4335", "#FBBC05", "#34A853"]
                    },
                    shape: {
                      type: ["circle"],
                      stroke: {
                        width: 0,
                        color: "#fff"
                      },
                      polygon: {
                        nb_sides: 5
                      },
                      image: {
                        src: "https://mpng.subpng.com/20171216/6c0/google-png-5a3554027e9924.3682726615134443545186.jpg",
                        width: 100,
                        height: 100
                      }
                    },
                    opacity: {
                      value: 1,
                      random: false,
                      anim: {
                        enable: false,
                        speed: 1,
                        opacity_min: 0.1,
                        sync: false
                      }
                    },
                    size: {
                      value: 8,
                      random: true,
                      anim: {
                        enable: false,
                        speed: 10,
                        size_min: 10,
                        sync: false
                      }
                    },
                    line_linked: {
                      enable: true,
                      distance: 150,
                      color: "#808080",
                      opacity: 0.4,
                      width: 1
                    },
                    move: {
                      enable: true,
                      speed: 5,
                      direction: "none",
                      random: true,
                      straight: false,
                      out_mode: "out",
                      bounce: true,
                      attract: {
                        enable: false,
                        rotateX: 600,
                        rotateY: 1200
                      }
                    }
                  },
                  interactivity: {
                    detect_on: "canvas",
                    events: {
                      onhover: {
                        enable: true,
                        mode: "grab"
                      },
                      onclick: {
                        enable: true,
                        mode: "push"
                      },
                      resize: true
                    },
                    modes: {
                      grab: {
                        distance: 140,
                        line_linked: {
                          opacity: 1
                        }
                      },
                      bubble: {
                        distance: 400,
                        size: 40,
                        duration: 2,
                        opacity: 8,
                        speed: 3
                      },
                      repulse: {
                        distance: 200,
                        duration: 0.4
                      },
                      push: {
                        particles_nb: 4
                      },
                      remove: {
                        particles_nb: 2
                      }
                    }
                  },
                  retina_detect: true
                }} />
                <div className="image">
                  <img className="img" src={Google} alt="logo"/>
                </div>
                
            </div>
          </div>
  );
}

export default App;
