import React from "react";
class Info extends React.Component{
    constructor(props){
        super(props);
    }
    render(){
    const title = "This is the title";
    const showTitle = true;
    // return(
    //   <div>
    //     <h1>{title}</h1>
    //     {/* <h1>{showTitle ? title : "No Title"}</h1> */}
    //     <p>Manage your stuff.</p>
    //   </div>
    // );
    if(showTitle){
      return(
        <div>
          <h1>{title}</h1>
          {/* <h1>{showTitle ? title : "No Title"}</h1> */}
          <p>Manage your stuff.</p>
        </div>
      );
    }
    else{
      return <p>empty</p>;
    }
    }
}
// function Info(){
//     const title = "This is the title";
//     const showTitle = true;
//     // return(
//     //   <div>
//     //     <h1>{title}</h1>
//     //     {/* <h1>{showTitle ? title : "No Title"}</h1> */}
//     //     <p>Manage your stuff.</p>
//     //   </div>
//     // );
//     if(showTitle){
//       return(
//         <div>
//           <h1>{title}</h1>
//           {/* <h1>{showTitle ? title : "No Title"}</h1> */}
//           <p>Manage your stuff.</p>
//         </div>
//       );
//     }
//     else{
//       return <p>empty</p>;
//     }
//   }

export default Info; 