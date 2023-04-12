window.addEventListener('load', () => {
	programs = JSON.parse(localStorage.getItem('programs')) || [];
	const nameInput = document.querySelector('#name');
	const newProgramForm = document.querySelector('#new-program-form');

	const username = localStorage.getItem('username') || '';

	nameInput.value = username;

	nameInput.addEventListener('change', (e) => {
		localStorage.setItem('username', e.target.value);
	})


	newProgramForm.addEventListener('submit', (e) => {
		e.preventDefault();

		const program = {
			exercise: e.target.elements.exercise.value,
			weight:e.target.elements.weight.value,
			sets: e.target.elements.sets.value,
			reps: e.target.elements.reps.value,
			category: e.target.elements.category.value,
			done: false,
			createdAt: new Date().getTime()
		}

		programs.push(program);

		localStorage.setItem('programs', JSON.stringify(programs));

		e.target.reset();

		programs.sort((a, b) => (a.category > b.category) ? 1 : -1)

		DisplayPrograms()

	})

	programs.sort((a, b) => (a.category > b.category) ? 1 : -1)

	DisplayPrograms()
})


function DisplayPrograms () {
	const programList = document.querySelector('#program-list');
	programList.innerHTML = "";

	programs.forEach(program => {
		const exerciseItem = document.createElement('div');
		exerciseItem.classList.add('exercise-item');

		const label = document.createElement('label');
		const input = document.createElement('input');
		const span = document.createElement('span');
		const content = document.createElement('div');
		const actions = document.createElement('div');
		const deleteButton = document.createElement('button');

		input.type = 'checkbox';
		input.checked = program.done;
		span.classList.add('bubble');

		if (program.category == '2') {
			span.classList.add('day2');
		} else if (program.category == '3') {
			span.classList.add('day3');
		} else {
			span.classList.add('day1');
		}

		content.classList.add('exercise-content');
		actions.classList.add('actions');
		deleteButton.classList.add('delete');

		content.innerHTML = `<input type="text" value="${program.exercise}: ${program.weight}kg  x${program.sets}  x${program.reps}" readonly>`;
		deleteButton.innerHTML = 'Delete';
		label.appendChild(input);
		label.appendChild(span);
		actions.appendChild(deleteButton);
		exerciseItem.appendChild(label);
		exerciseItem.appendChild(content);
		exerciseItem.appendChild(actions);
		
		programList.appendChild(exerciseItem);

		if (program.done) {
			exerciseItem.classList.add('done');
		}

		input.addEventListener('click', (e) => {
			program.done = e.target.checked;
			localStorage.setItem('programs', JSON.stringify(programs));

			if (program.done) {
				exerciseItem.classList.add('done');
			} else {
				exerciseItem.classList.remove('done');
			}

			DisplayPrograms();
		})

		deleteButton.addEventListener('click', (e) => {
			programs = programs.filter(t => t != program);
			localStorage.setItem('programs', JSON.stringify(programs));
			DisplayPrograms();
		})
		
	})

	const reset = document.querySelector('#reset-button');
	reset.addEventListener('click', (e) => {
		programs.forEach(program => {
			localStorage.setItem('programs', JSON.stringify(programs));
			program['done'] = false;
		})
		DisplayPrograms();
	})
		

}
