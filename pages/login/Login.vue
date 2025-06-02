<script setup lang="ts">
interface ILoginForm {
    email: string
    password: string
}

const form = ref<ILoginForm>({
    email: '',
    password: ''
})

const error = ref('')

async function login(email: string, password: string) {
    return new Promise<{ isSuccess: boolean; message?: string }>((resolve) => {
        // NOTE(Daniel): make sure to call the MongoDB/Mongoose API here for use
        setTimeout(() => {
            if (!email && !password) {
                resolve({ isSuccess: false })
            }

            resolve({ isSuccess: true })
        }, 1800)
    })
}

async function onSubmit() {
    error.value = ''

    const { email, password } = form.value
    const result = await login(email, password)

    if (!result.isSuccess) {
        error.value = result.message || 'Error: login failed...'
    }
}
</script>

<template>
    <form method="get" action="" v-on:submit="onSubmit()">
        <h1>Sign yourself in?</h1>

        <label for="email">e-Mail</label>
        <input type="email" v-model="form.email" required />

        <label for="password">Password</label>
        <input type="password" v-model="form.password" required />

        <button type="submit">Sign yourself in</button>
    </form>
</template>
