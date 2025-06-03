<script setup lang="ts">
defineProps({
    quantity: Number
})

const emit = defineEmits(['deactivate', 'succession'])

type VerificationCardType = {
    id: number
    uuid: string
    name: string
    secret: string
    expiry: string
}

const card = ref<VerificationCardType>({
    id: 0,
    uuid: '',
    name: '',
    secret: '',
    expiry: ''
})

const validate = computed(() => {
    let retval: boolean = false
    if (
        !card.value.id &&
        !card.value.uuid &&
        !card.value.name &&
        !card.value.secret
    )
        retval = true
    return retval
})

const pay = computed(() => {
    const validated = validate
    if (!validated) emit('deactivate')

    emit('succession')
})
</script>

<template></template>
