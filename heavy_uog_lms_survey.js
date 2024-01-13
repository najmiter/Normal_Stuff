// coded by the people for the people

const thing = document.getElementById('resourceobject')?.contentWindow;
if (thing) {
  let counter = 0;
  const total_subjects = 6; // Change to your number of subjects
  const delay = 2000; // You can change the <2000 ms> to something else depending upon your internet speed
  for (; counter < total_subjects * 2; counter++) {
    setTimeout(() => {
      thing.document.querySelectorAll('input')
      .forEach(each => {
        if (each.value === '1' || each.value === '225') // could've just selected these with the css selectors but anyway 😁
          each.checked = true;
      })
      
      thing.document.querySelector(`input[type='submit']`).click();
    }, counter * delay)
  }
  
  setTimeout(() => {
    document.getElementById('actionmenuaction-6').click()
  }, counter * delay);
} else {
  console.error(`Please make sure that:
    1. You're logged into your LMS.
    2. Responsive Mode is turned off.`);
}
