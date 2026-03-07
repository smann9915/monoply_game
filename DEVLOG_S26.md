# Developer Log (DEVLOG.md)
## Monopoly Board Simulator (Spring 2026)

Minimum **6 entries** required.

Each entry must document learning and reasoning. Fabricated bugs are not expected.

---

## Allowed Entry Types
Each entry may be one of the following:

1) **Bug Fix Entry**
- The issue encountered.
- Error messages or symptoms.
- Attempts made.
- Final resolution.

2) **Edge Case / Testing Entry**
- A failure discovered through testing.
- The specific input/state that caused it.
- The change you made to handle it correctly.

3) **Engineering Decision Entry (up to 2 allowed)**
- A design decision you made.
- An alternative approach you considered.
- Why you chose one approach over another (tradeoffs).

---

### Entry 1
**Date:** 2026-02-26  
**Entry Type:** Engineering Decision.    
**Task worked on:** Linked List creation. \
**Error message / symptom (if applicable):** N/A \
**What I tried:** This was the only way I could think of  
**Fix / resolution (or final decision):** I decided to
use a for loop and immediately append the data for each space to the 
list and have the data just be an index from 1 to 40 \
**Commit(s):**  
Base LL creation
---

### Entry 2
**Date:** 2026-02-28  
**Entry Type:** Engineering Decision  
**Task worked on:** Changed my work to the template \
**Issue or decision:** I didn't see the template cpp file so i moved all of my work over and made it compatible with the template. \
**Error message / symptom (if applicable):**  N/A \
**What I tried:** Nothing to "try" just moved work over \
**Fix / resolution (or final decision):** I ended up using my old implementation with the template to complete both core's A and C. \
**Commit(s):**  
Change to template + Core's A and C
---

### Entry 3
**Date:** 2026-03-01  
**Entry Type:** Edge Case \
**Task worked on:** The printBoardOnce function \
**Issue or decision:** I decided to use a while loop instead of a for loop to traverse all the boards spaces. \
**Error message / symptom (if applicable):** N/A \
**What I tried:** A for loop but, I didn't like the for loop format didn't sit right with me. \
**Fix / resolution (or final decision):**  I landed on a while loop that checks for the break condition after the temp->next so that it can start with the headnode and end by checking if we are at the head node. \
**Commit(s):**  
AddMany() and printOnce()
---

### Entry 4
**Date:** 2026-03-01  
**Entry Type:** Edge Case \
**Task worked on:** The AddMany function \
**Issue or decision:** Returning the count variable.
**Error message / symptom (if applicable):** N/A
**What I tried:** I initially had I established outside the for loop so that i could return it when the loop was done. \
**Fix / resolution (or final decision):** I realized I could just return the size of the vector if all spaces were passed. \
**Commit(s):**  
AddMany() and printOnce()
---

### Entry 5
**Date:** 2026-03-07  
**Entry Type:** Bug Fix 
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  

---

### Entry 6
**Date:** YYYY-MM-DD  
**Entry Type:** Bug Fix / Edge Case / Engineering Decision  
**Task worked on:**  
**Issue or decision:**  
**Error message / symptom (if applicable):**  
**What I tried:**  
**Fix / resolution (or final decision):**  
**Commit(s):**  
