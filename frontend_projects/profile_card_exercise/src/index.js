import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import "./styles.css";

const skills = [
  {
    skill: "Biting",
    level: "advanced",
    color: "red",
  },
  {
    skill: "Swimming",
    level: "advanced",
    color: "blue",
  },
  {
    skill: "Charming",
    level: "advanced",
    color: "orange",
  },
  {
    skill: "Adorable",
    level: "advanced",
    color: "pink",
  },
  {
    skill: "Selflessness",
    level: "intermediate",
    color: "yellow",
  },
  {
    skill: "Nom nom",
    level: "beginner",
    color: "grey",
  },
];

function App() {
  return (
    <div className="card">
      <Avatar />
      <div className="data">
        <Intro />
        {/* Should contain one Skill component
        for each web dev skill that you have,
        customized with props */}
        <SkillList />
      </div>
    </div>
  );
}

function Avatar() {
  return <img className="avatar" src="small.jpg" alt="Jeff the Landshark" />;
}

function Intro() {
  return (
    <div>
      <h1>Jeff the Landshark</h1>
      <p>
        Hi! I’m Jeff, a landshark with tiny legs, a big appetite, and an even
        bigger heart. I love snacks, belly rubs, and causing just a little chaos
        with my favorite humans—especially when it gets me more food!
      </p>
    </div>
  );
}

function SkillList() {
  return (
    <div className="skill-list">
      {skills.map((skill) => (
        <Skill skill={skill.skill} color={skill.color} level={skill.level} />
      ))}
    </div>
  );
}

function Skill({ skill, color, level }) {
  return (
    <div className="skill" style={{ backgroundColor: color }}>
      <span>{skill}</span>
      <span>{level === "beginner" && "👶"}</span>
      <span>{level === "intermediate" && "👍"}</span>
      <span>{level === "advanced" && "💪"}</span>
    </div>
  );
}

const rootElement = document.getElementById("root");
const root = createRoot(rootElement);

root.render(
  <StrictMode>
    <App />
  </StrictMode>
);
