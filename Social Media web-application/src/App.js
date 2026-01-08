import './App.css';
import Feed from './components/feed/Feed';
import Rightbar from './components/rightbar/Rightbar';
import Sidebar from './components/sidebar/Sidebar';
// import Home from'./pages/Home/Home';
import Topbar from './pages/topbar/Topbar';
import "./pages/Home/home.css"


function App() {
  return (
   <>
   <Topbar/>
   <div className='homecontainer displayflex'>
   <Sidebar/>
   <Feed/>
   <Rightbar/>
  
   </div>

   {/* <Home/> */}
   </>
  );
}

export default App;
