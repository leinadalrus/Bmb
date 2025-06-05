<script setup lang="ts">
import bcrypt from 'bcryptjs'
import jsonwebtoken from 'jsonwebtoken'
import { UserModelAssembler } from '~/src/models/UserSchema'

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
// JWT-based login authentication
const email = async (request: Request, response: Response) => {
    const data = request.body

    const user = await UserModelAssembler.findOne({
        data
    })

    if (!user) return { status: 409 }

    return { status: 202, form: form }
}

const password = async (request: Request, response: Response) => {
    const data = request.body

    const user = await UserModelAssembler.findOne({
        data
    })

    if (!user) return { status: 401 }

    if (
        (await bcrypt.compare(
            form.value.password,
            process.env['SECRET_HASH']
        )) == true
    )
        if (!user) return { status: 401 }

    return { status: 202, form }
}

const authenticate = async (request: Request, response: Response) => {
    try {
        // request.header('Authorization').replace('Bearer', '')
        const headers = request.headers
        const data = request.formData

        for (let key in headers.keys) {
            if (key == 'Authorization') headers.set('Authorization', 'Bearer')
        }
        const hs = String(headers.get('Authorization'))

        const bearers = jsonwebtoken.verify(hs, process.env['SECRET_KEY'])

        const user = await UserModelAssembler.findOne({
            data
        })
        if (!user) return { status: 401 }

        await bcrypt.compare(user.username, form.value.email)
        await bcrypt.compare(user.password, form.value.password)

        const tokenized = jsonwebtoken.sign(
            {
                email: user.email,
                password: user.password
            },
            // eslint-disable-next-line no-undef
            process.env['SECRET_KEY']
        )

        return { status: 200, tokenized: tokenized }
    } catch (err) {
        console.table(err)
        return { status: 500 }
    }
}

const findEmail = async () => {
    const find = await UserModelAssembler.findOne(
        { email: form.value.email },
        'email'
    )
        .select('email')
        .lean()
    const result = String(find)

    return result
}
</script>

<template>
    <form method="get" action="" :onsubmit="onSubmit()">
        <h1>Sign yourself in?</h1>

        <label for="email">e-Mail</label>
        <input type="email" v-model="form.email" required />

        <label for="password">Password</label>
        <input type="password" v-model="form.password" required />

        <button type="submit">Sign yourself in</button>

        <input type="checkbox" name="rememberMe" id="" value="Remember me?" />
    </form>
</template>
