const questions = document.querySelectorAll(".qtext");
const answers = document.querySelectorAll(".answer");
const t_question = questions.length;

let all_ = "";

for (let i = 0; i < t_question; i++) {
    all_ += `${questions[i]?.innerText ?? ""}\n${answers[i]?.innerText ?? ""}\n\n`;
}

console.log(all_);
