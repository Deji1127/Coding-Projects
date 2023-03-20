import './App.css';
import Info from "./Info.js";
function App() {
  return (
    <div className="App">
      <Info/>
      <AddItem text="Ahmed" number={7}/>
      <AddItem text="Saja"/>
    </div>
  );
}


function AddItem(props){
  const value = props.text;
  return( 
    <form>
      <label for="text-form"> Type something: </label>
      <input type="text" value={props.text} id="text-form" />
      <p>{props.number}</p>
    </form>
  );
}
export default App;