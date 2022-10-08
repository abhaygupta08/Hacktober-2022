import React from "react"

export default function About(props) {
    return (
        <section className="about-section">
            <h1 className="about-h1">
                About
            </h1>
            <p>{props.description} 
            </p>
        </section>
    )
}