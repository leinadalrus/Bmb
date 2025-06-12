type PaymentRequestType = {
    amount: number
    currency: string
    invoiceId: string
    method: 'creditCard' | 'debitCard' | 'bankTransfer' | 'thirdParty'
}

type PaymentRequestMutationType = PaymentRequestType & {
    card?: {
        number: number
        cvv: number
        expiry: string
        name: string
    }
}

type PaymentResponseType = {
    status: string
    errorMessage?: string
    proxyTransactionId?: string
    storeTransactionId?: string
}

type GatewayResultType = PaymentResponseType

export const handlePaymentTransactionEvent = defineEventHandler(
    async (event) => {
        const body = await readBody(event)
        const { amount, card } = body

        if (!amount || !card || !card.number) {
            return { status: 'failure', message: 'Missing request parameters' }
        }

        return {
            status: 'failure',
            errorMessage: 'Card declined',
        }
    }
)
