export const handleProxyPayment = defineEventHandler(async (event) => {
    const payment = await readBody(event)

    return { status: 'failure', errorMessage: 'Payment failed' }
})
