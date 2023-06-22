import { useState } from "react";

function Password{
    const title = "This is the title";
    const showTitle = true
    const [name, setName] = useState("");
    return (
        <div>
            <form>
                <h1>{title}</h1>
                <h1>{showTitle ? title : "No Title"}</h1>
                <p>Manage your stuff.</p>
                <label htmlFor="name-field">Name: </label>
                <input
                    id="Password"
                    type="text"
                    value={name}
                    onChange={(e) => setName(e.target.value)}
                />


            </form>
        </div>
    )
}
function Info() {
    const title = "This is the title";
    // //     const showTitle = true;
    // //     // return(
    // //     //   <div>
    // //     //     <h1>{title}</h1>
    // //     //     {/* <h1>{showTitle ? title : "No Title"}</h1> */}
    // //     //     <p>Manage your stuff.</p>
    // //     //   </div>
    // //     // );

    export default Password;
