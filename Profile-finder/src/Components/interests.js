import React from "react"

export default function Interests(props){
    return(
        <section className="interests-section">
            <h1 className="interests-h1">Info</h1>
            <p><b>Followers: </b>{props.followers}</p>
            <p><b>Following: </b>{props.following}</p>
            <p><b>Repositories: </b>{props.repos}</p>

        </section>
    )
}