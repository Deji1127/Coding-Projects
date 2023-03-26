import "./App.css";
import SearchBar from "./SearchBar";
//import Info from "./Info.js";
//import { useState } from "react";


function App() {
  return (
    <div className="App">
    <SearchBar />
    </div>
  )
}
//function App() {
  // return (
  //   <div className="App">
  //     <Info title="This is the title" />
  //     <ButtonState />
  //     {/* <AddItem text="Ahmed" number={7}/>
  //     <AddItem text="Saja"/> */}
  //   </div>
  // );
//}
// function AddItem(props){
//   const value = props.text;
//   return(
//     <form>
//       <label for="text-form"> Type something: </label>
//       <input type="text" value={props.text} id="text-form" />
//       <p>{props.number}</p>
//     </form>
//   );
// }
// function ButtonState() {
//   //this is the button function
//   const [title, setTitle] = useState("");
//   const [count, setCount] = useState(0);

//   const updateTitleClicked = () => {
//     setTitle("We got titlesss"); //function passed into onClick //shows a new title
//   };
//   const updateCounterClicked = () => {
//     setCount(count + 1);
//   };
//   return (
//     <div>
//       {/* <p>Title: {title}</p>
//       <p>Counter: {count}</p> */}
//       <Data title={ title } count={count}/>
//       <button onClick={updateTitleClicked}>About me </button>{/*onClick is responsible for what happens after the button is clicked*/}
//       <button onClick={updateCounterClicked}>Links and Socials</button>
//       {/*requires a function to be passed. Function determines what happens*/}
//     </div>
//   );
// }

// function Data(props) {
//   return (
//     <div>
//       <p>Title: {props.title}</p>
//       <p>Count: {props.count}</p>
//     </div>
//   );
// }

export default App;
