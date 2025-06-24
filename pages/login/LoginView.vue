<script setup lang="ts">
import { ref } from 'vue'
import bcrypt from 'bcryptjs'
import jsonwebtoken from 'jsonwebtoken'
import { UserModelAssembler } from '~/server/models/UserSchema'

interface ILoginForm {
    email: string
    password: string
}

const form = ref<ILoginForm>({
    email: '',
    password: ''
})

const statusCode = ref(0)
const erroneous = ref('')

// JWT-based login authentication
const email = async (request: Request) => {
    const data = request.body

    const user = await UserModelAssembler.findOne({
        data
    })

    if (!findEmail) return { statusCode: 409, JSON: erroneous }
    if (!user) return { statusCode: 409, JSON: erroneous }

    return { statusCode: 202, JSON: form }
}

const password = async (request: Request) => {
    const data = request.body

    const user = await UserModelAssembler.findOne({
        data
    })

    if (!user) return { statusCode: 401, JSON: erroneous }

    return { statusCode: 202, JSON: form }
}

const authenticate = async (request: Request) => {
    const headers = new Headers()

    // NOTE(Authorisation): request.header('Authorization').replace('Bearer', '')
    headers.set('Content-Type', 'application/json')
    headers.set('Accept', 'application/json')

    const requestInfo = new Request(request.url, {
        method: request.method,
        headers: headers
    })

    try {
        const data = request.formData

        const user = await UserModelAssembler.findOne({
            data
        })
        if (!user) return { statusCode: 401, JSON: erroneous }

        await bcrypt.compare(user.username, form.value.email)
        await bcrypt.compare(user.password, form.value.password)

        return fetch(requestInfo)
            .then((d) => d.json())
            .then((d) => {
                statusCode.value = 200
                jsonwebtoken.sign(
                    {
                        email,
                        password
                    },
                    // eslint-disable-next-line no-undef
                    process.env['SECRET_KEY']
                )
                // We return as an interfaced-array type-
                return d as ILoginForm[] // -because of our JSON output value
            })
    } catch (err) {
        console.table(err)
        return { statusCode: 500, JSON: erroneous }
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
    <form method="get" action="" :submit="authenticate">
        <h1>Sign yourself in?</h1>

        <label for="email">e-Mail</label>
        <input type="email" v-model="form.email" required />

        <label for="password">Password</label>
        <input type="password" v-model="form.password" required />

        <button type="submit">Sign yourself in</button>

        <input type="checkbox" name="rememberMe" id="" value="Remember me?" />
    </form>
</template>
